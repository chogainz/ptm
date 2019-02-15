<?php
// creates a private class
class Email{

    // creates private variables
    private $_username;
    private $_password;
    private $_first_name;
    private $_last_name;
    private $_dob;
    private $_address;
    private $_postcode;
    private $_email;
	private $_message;
	private $_sender;
	private $_to;
	private $_headers;
	private $_form_data;
	private $_errors;


	//constructor method assigns the private variables
    public static function EmailUser($_subject) {
     
	 	// set to false
	 	$_errors = false ;
	 	
	    // filters the posts for submitted data
        $_username = $_POST['username'];
        $_password = $_POST['password'];
        $_first_name = $_POST['first_name'] ? $_first_name = $_POST['first_name'] : $_errors = true ;
        $_last_name = $_POST['last_name'] ?  $_last_name = $_POST['last_name'] : $_errors = true ;
        $_dob = $_POST['dob'] ? $_dob = $_POST['dob'] : $_errors = true ;
        $_address = $_POST['address'] ? $_address = $_POST['address']: $_errors = true ;
        $_postcode = $_POST['postcode'] ? $_postcode = $_POST['postcode'] : $_errors = true ;
        $_email = $_POST['email'] ? $_email = $_POST['email'] : $_errors = true ;
	   
	   $_form_data = array(
	    "username" => $_username, 
        "password" => $_password, 
        "first_name" => $_first_name,
        "last_name" => $_last_name, 
        "dob" => $_dob,
        "address" => $_address, 
        "postcode" => $_postcode, 
        "email" => $_email
		); 
	   
	   
	   if(!($_errors)){
	   
	    $_sender = "river99@live.co.uk";
        // email to me and user
        $_to = $_email . "," . $_sender;

		// message
		$_message = "Welcome to ptm.co.uk | $_username\n
		$_subject Details\r
		First name: $_first_name\r
		Last name: $_last_name\r
		dob: $_dob\r
		Address: $_address\r
		Postcode: $_postcode\r
		Email: $_email\r";

		// headers
		$_headers  =  "From:info@ptm.com \r\n"; // must be a .com otherwise wont send
		$_headers .=  "Reply-To:river99@live.co.uk \r\n";
		$_headers .=  "Return-Path:register@ptm.co.uk \r\n";
		
		$output = mail($_to,$_subject,$_message,$_headers) ?
		"Confirmation Email Sent" : "There was a problem emailin you!";
	   
	   } else {
		$output = "unable to set variables";  
		var_dump($_errors);  
		 
	   }
	return $output;
	}
}

?>
