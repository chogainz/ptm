<?php
	class ProcessForm{
	
	// private variables
	private $_username;
	private $_output;
	private $_strength;
	private $_score;
	private $_name;
	private $_valid;


	// validation function
	public static function validateInfo(){
	
	// assigns variables to default values
	 $_strength	= array("None","Poor", "OK", "Good", "Very Good", "Excellent"); 
	 $_score	= null;
	 $_output	= null;
	 $_valid	= null;
	   
   // loops through all the keys in $_REQUEST; 
	foreach($_REQUEST as $key => $value){
	
		$_name = $_REQUEST[$key];
	
		$_output = "<div class='error'><h3>";
		
		// checks that only input is validated
		if($key!="token" && $key!="login"){
		
			if(strlen($_name)<1){
			$_score = 0;
			$_valid = "Empty";
			}
			else if(strlen($_name)<5){
			$_score = 1;
			$_valid = "Not enough Characters";
			}
			if(strlen($_name)>=5){
			$_score = 2;
			$_valid = "Accepted";
			if(strlen($_name)>=8){
			$_score = 3;
			}
			if(strlen($_name)>=10){
			$_score = 4;
			}
			if (preg_match("/[a-z]/", $_name) && preg_match("/[A-Z]/", $_name)){
			$_score = 4;
			}
			if (preg_match("/[0-9]/", $_name)){
			$_score = 4;
			}
			if (preg_match("/.[!,@,#,$,%,^,&,*,?,_,~,-,£,(,)]/", $_name)){
			$_score = 5;
				}
			}
		 // uses the values returned from vaiables to create dynamic validation 
		 $_output .=  "</br>" . ucfirst($key) . ": " . $_valid . " Strength: ". $_strength[$_score];
		}	
		$_output .= "</h3></div>";			
		
		echo $_output;		
			}
	
		}
	
	}
?>