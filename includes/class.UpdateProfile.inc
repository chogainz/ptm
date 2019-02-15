<?php
// creates a private class
class UpdateProfile {

    // creates private variables
    private $_first_name;
    private $_last_name;
    private $_dob;
    private $_address;
    private $_postcode;
    private $_email;
    private $_user_id;
    private $_errors;
    private $_token;

    //constructor method assigns the private variables
    public function __construct() {
        //errors var empty array
        $this->_errors = array();

        // filters the posts for submitted data
        $this->_first_name = $this->filter($_POST['first_name']);
        $this->_last_name = $this->filter($_POST['last_name']);
        $this->_dob = $this->filter($_POST['dob']);
        $this->_address = $this->filter($_POST['address']);
        $this->_postcode = $this->filter($_POST['postcode']);
        $this->_email = $this->filter($_POST['email']);
        $this->_user_id = $_SESSION['user_id'];

        // assings token var to post
        $this->_token = $_POST['token'];
    }

    // process function checks all validation
    public function process() {
        // if token is valid and data is valid call profile function
        if ($this->isTokenValid() && $this->isDataValid())
            $this->profile();
        return count($this->_errors) ? 0 : 1;
    }

    public function filter($var) {
        return preg_replace('/[^-a-zA-Z0-9@. \/]/', '', $var);
    }

    //verify data against database
    public function profile() {
       		// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();  
	    //inserts username and password in to users table
         $data = ("UPDATE user SET
							first_name='{$this->_first_name}',
                            last_name='{$this->_last_name}', 
                            dob='{$this->_dob}', 
                            address='{$this->_address}',
                            postcode='{$this->_postcode}', 
                            email='{$this->_email}'
							WHERE user_id ='{$this->_user_id}' ");

			$result = $mysqli->query($data);
        if ( $mysqli->affected_rows < 1)
        // checks if data has been succesfully inputed
            $this->_errors[] = 'Nothing Updated';
    }

    //verify data is valid
    public function isDataValid() {
        // names must be between 2 and 22 characters
         if (empty($this->_first_name) || !preg_match('/^[a-zA-Z0-9]{2,22}$/', $this->_first_name))
            $this->_errors[] = 'Invalid first name Must be between 2 and 22 characters';
        else if (empty($this->_last_name) || !preg_match('/^[a-zA-Z0-9]{2,22}$/', $this->_last_name))
            $this->_errors[] = 'Invalid last name Must be between 2 and 22 characters';
        //restricts day to 01-31, month to 01-12 and year to 1900-2099 (also allowing / - or . between the parts of the date) 
        else if (empty($this->_dob) || !preg_match('/^(0?[1-9]|[12][0-9]|3[01])[\/\ ](0?[1-9]|1[0-2])[\/\ ](19|20)\d{2}$/', $this->_dob))
            $this->_errors[] = 'Invalid DOB | Must be DD/MM/YYYY format';
        else if (empty($this->_address))
            $this->_errors[] = 'Invalid address';
        // checks if valid postal code
        else if (empty($this->_postcode) || !preg_match('/^(([A-PR-UW-Z]{1}[A-IK-Y]?)([0-9]?[A-HJKS-UW]?[ABEHMNPRVWXY]?|[0-9]?[0-9]?))\s?([0-9]{1}[ABD-HJLNP-UW-Z]{2})$/', $this->_postcode))
            $this->_errors[] = 'Invalid postcode | Must be AA11 9AA format';
        // checks is valid email using regular expression
        else if (empty($this->_email) || !preg_match('/^[_\.0-9a-zA-Z-]+@([0-9a-zA-Z][0-9a-zA-Z-]+\.)+[a-zA-Z]{2,6}$/', $this->_email))
            $this->_errors[] = 'Invalid email';
        // return true or false 
        return count($this->_errors) ? 0 : 1;
    }

    //check if the form submission is valid
    public function isTokenValid() {
        if (!isset($_SESSION['token']) || $this->_token != $_SESSION['token'])
            $this->_errors[] = '';

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
