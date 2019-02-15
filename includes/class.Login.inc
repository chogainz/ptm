<?php
// creates a private class
class login {

    // creates private variables
    private $_id;
    private $_username;
    private $_password;
    private $_sha1;
    private $_errors;
    private $_access;
    private $_login;
    private $_token;

    //constructor method assigns the private variables
    public function __construct() {
        //errors var empty array
        $this->_errors = array();

        //checks if login button has been submitted true or false value;
        $this->_login = isset($_POST['login']) ? 1 : 0;

        // access var checks if access granted to members area ( default 0 assigns to false 1 is true)
        $this->_access = 0;

        // token var assigned to token no need for filter because being used for a comparisson only
        $this->_token = $_POST['token'];

        // deault to 0
        $this->_id = 0;

        // if form submited filter out the post username Var and assign to username. else assign it to username session Var 
        $this->_username = ($this->_login) ? $this->filter($_POST['username']) : $_SESSION['username'];
        // contains origonal password text, required to perform data validation
        //if login submission filter out the post password Var and assign to password. else assign it to empty string
        $this->_password = ($this->_login) ? $this->filter($_POST['password']) : '';

        // sha1 contains password in encripted format, if login encript password else assign session password Var
        // Encripts password
		$this->_sha1 =  hash('sha1' ,$this->_password);
		$this->_sha1 = ($this->_login) ? $this->_sha1 : $_SESSION['password'];
  
	}

    //check if user is logged in
    public function isLoggedIn() {
        // check if form has been submitted if so call verify post function else verify session
        ($this->_login) ? $this->verifyPost() : $this->verifySession();
        // return access true or false
        return $this->_access;
    }

    public function filter($var) {
		 // includes special chars when matched and stops sql injection
	
        return preg_replace('/[^a-zA-Z0-9]/', '', $var);
    }

    //verify post data
    public function verifyPost() {
        try {
            if (!$this->isTokenValid())
                throw new Exception('Invalid form submission');

            if (!$this->isDataValid())
                throw new Exception('Invalid username/password');

            if (!$this->verifyDatabase())
                throw new Exception('Wrong username/password');

            $this->_access = 1;
            $this->registerSession();
        } catch (Exception $e) {
            $this->_errors[] = $e->getMessage();
        }
    }

    //verify session data
    public function verifySession() {
        // if session session exists and database can be verified
        if ($this->sessionExist() && $this->verifyDatabase())
        // sets acces var to true
            $this->_access = 1;
    }

    //verify data against database
    public function verifyDatabase() {
		// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();
        // use passmd5 because passwords from table are already encripted
        $data = ("SELECT user_id FROM user WHERE username = '$this->_username'  AND password = '$this->_sha1'");			
		
		$result = $mysqli->query($data);
        if (mysqli_num_rows($result)) {
            $row = $result->fetch_assoc();
            $this->_user_id = $row["user_id"];
		
            return true;
        } else {

            return false;
        }
    }

    //verify data is valid
    public function isDataValid() {
		
        // checks if username and password are between 5 and 12 characters
        return(preg_match('/^[a-zA-Z0-9]{5,16}$/', $this->_username)
                && preg_match('/^[a-zA-Z0-9]{6,18}$/', $this->_password)) ? 1 : 0;
    }

    //check if the form submission is valid
    public function isTokenValid() {
		return(!isset($_SESSION['token']) || $this->_token != $_SESSION['token']) ? 0 : 1;
		
    }

    //register a session
    public function registerSession() {
        $_SESSION['user_id'] = $this->_user_id;
        $_SESSION['username'] = $this->_username;
	    $_SESSION['password'] = $this->_sha1;
    }

    //check if session exists
    public function sessionExist() {
        // cehck if both username are set return true else return false;
		return(isset($_SESSION['username']) && isset($_SESSION['password'])) ? 1 : 0;
    }

    //displays errors that occur during processing of the form
    public function showErrors() {
      
        foreach ($this->_errors as $key => $value)
           $this->_errors = $value;
			return $this->_errors;
    }

}

?>
