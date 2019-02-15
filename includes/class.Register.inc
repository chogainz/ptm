<?php
// creates a private class
class Register {

    // creates private variables
    private $_username;
    private $_password;
	private $_password_confirm;
    private $_sha1;
    private $_first_name;
    private $_last_name;
    private $_dob;
    private $_address;
    private $_postcode;
    private $_email;
    private $_errors;
    private $_token;
	
	//constructor method assigns the private variables
    public function __construct() {
        //errors var empty array
        $this->_errors = array();

        // filters the posts for submitted data
        $this->_username = $this->filter($_POST['username']);
        $this->_password = $this->filter($_POST['password']);
		$this->_password_confirm = $this->filter($_POST['password_confirm']);
        $this->_first_name = $this->filter($_POST['first_name']);
        $this->_last_name = $this->filter($_POST['last_name']);
        $this->_dob = $this->filter($_POST['dob']);
        $this->_address = $this->filter($_POST['address']);
        $this->_postcode = $this->filter($_POST['postcode']);
        $this->_email = $this->filter($_POST['email']);


        // assings token var to post
        $this->_token = $_POST['token'];
       
	    // sets _sha1 to password
        $this->_sha1 = $this->_password;

		// encripts password
		
		$this->_sha1 =  hash('sha1' ,$this->_sha1);
		//var_dump($this->_sha1);
    }

    // process function checks all validation
    public function process() {
        // if token is valid and data is valid call register function
        if ($this->isTokenValid() && $this->isDataValid())
            $this->register();

        return count($this->_errors) ? 0 : 1;
    }

    public function filter($var) {
        // includes special chars when matched and stops sql injection
		return preg_replace('/[^-a-zA-Z0-9@. \/]/', '', $var);
    }

   
    //verify data against database
    public function userExists() {
		
		// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection(); 
		
        //inserts username and password in to users table
        $data =("SELECT user_id FROM user WHERE username ='{$this->_username}'");
		$result = $mysqli->query($data);
        return(mysqli_num_rows($result) > 0) ? 1 : 0;
    }

    //verify data against database
    public function register() {
		
		// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();
		
        $data = ("INSERT INTO user (username,password,first_name,
                           last_name,dob,address,postcode,email)
                           VALUES ('{$this->_username}',
                           '{$this->_sha1}',
                           '{$this->_first_name}',
                           '{$this->_last_name}',
                           '{$this->_dob}',
                           '{$this->_address}',
                           '{$this->_postcode}',
                           '{$this->_email}')");
						   
			$result = $mysqli->query($data);
        if ( $mysqli->affected_rows < 1)
        // checks if data has been succesfully inputed
            $this->_errors[] = 'could not process form';
    }

    //verify data is valid
    public function isDataValid() {
        if ($this->userExists())
            $this->_errors[] = 'username already taken';
        // username and password must match pattern
        else if (empty($this->_username) || !preg_match('/^[a-zA-Z0-9]{5,16}$/', $this->_username))
            $this->_errors[] = 'invalid username must be between 5 and 16 characters';
        else if (empty($this->_password) || !preg_match('/^[a-zA-Z0-9]{6,18}$/', $this->_password))
            $this->_errors[] = 'invalid password must be between 6 and 18 characters';
		 else if (empty($this->_password) || $this->_password != $this->_password_confirm)
            $this->_errors[] = "Password didn't match X";
        // names must be between 2 and 22 characters
        else if (empty($this->_first_name) || !preg_match('/^[a-zA-Z0-9]{2,22}$/', $this->_first_name))
            $this->_errors[] = 'invalid first name must be between 2 and 22 characters';
        else if (empty($this->_last_name) || !preg_match('/^[a-zA-Z0-9]{2,22}$/', $this->_last_name))
            $this->_errors[] = 'invalid last name must be between 2 and 22 characters';
        //restricts day to 01-31, month to 01-12 and year to 1900-2099 (also allowing / - or . between the parts of the date) 
        else if (empty($this->_dob) || !preg_match('/^(0?[1-9]|[12][0-9]|3[01])[\/\ ](0?[1-9]|1[0-2])[\/\ ](19|20)\d{2}$/', $this->_dob))
            $this->_errors[] = 'invalid dod | must be DD/MM/YYYY format';
        else if (empty($this->_address))
            $this->_errors[] = 'invalid address';
        // checks if valid postal code
        else if (empty($this->_postcode) || !preg_match('/^(([A-PR-UW-Z]{1}[A-IK-Y]?)([0-9]?[A-HJKS-UW]?[ABEHMNPRVWXY]?|[0-9]?[0-9]?))\s?([0-9]{1}[ABD-HJLNP-UW-Z]{2})$/', $this->_postcode))
            $this->_errors[] = 'invalid postcode | must be AA11 9AA format';
        // checks is valid email using regular expression
        else if (empty($this->_email) || !preg_match('/^[_\.0-9a-zA-Z-]+@([0-9a-zA-Z][0-9a-zA-Z-]+\.)+[a-zA-Z]{2,6}$/', $this->_email))
            $this->_errors[] = 'invalid email';


        // return true or false 
        return count($this->_errors) ? 0 : 1;
    }

    //check if the form submission is valid
    public function isTokenValid() {
        if (!isset($_SESSION['token']) || $this->_token != $_SESSION['token'])
           
			$this->_errors[] = 'invalid submission';

        // return true or false 
        return count($this->_errors) ? 0 : 1;
    }

    //displays errors that occur during processing of the form
    public function showErrors() {
     
        
        foreach ($this->_errors as $key => $value)
            $this->_errors = "$value";
			return $this->_errors;
    }

}

?>
