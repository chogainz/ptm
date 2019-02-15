<?php
// creates a private class
class Upload{

    // creates priv_name;
	private $_tmp_name;
	private $_new_file_name;
	private $_upload_file;
	private $_save_date;
	private $_errors;
	private $_upload_url;


	//constructor method assigns the private variables
    public static function UploadImage() {
     
	// declares variables 
	$_tmp_name = $_FILES['profile_pic']['tmp_name'];	
	$_upload_file =  $_FILES['profile_pic']['name'];
	$_save_date = date('dmy-Hms');
	
	$new_file_name = "../_uploads/" . "profile_pic_" . $_SESSION['user_id']  .".jpg";
	$_upload_url = 'http//'. $_SERVER['SERVER_NAME']
	.dirname($_SERVER['$_REQUEST_URI']).'/'. $new_file_name;

	//  checks if user has slected a file
	if (!empty($_FILES['profile_pic']['name'])) {
	
	// checks if the user has uploaded a valid file
	move_uploaded_file($_tmp_name , $new_file_name)? $output = "Profile Picture Changed" 
	: $output= "Sorry Could not upload your profile picture";
	
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();
		// puts name of a photo with users id on the end
		$data =("UPDATE user SET profile_pic ='$new_file_name'   WHERE user_id = '$_SESSION[user_id]' ");
		if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    	} else {
		$result = $mysqli->query($data);
			}

	} else {
	// checks submit button isset
	isset($_POST['change']) && $_POST['change']? $output = "Please select a Picture!": 0;
	
	
}
		 
			
	return $output;
		}	

	

		// checks if a profile pic has been set
		public static function CheckPic(){
		
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();
		$data =("SELECT profile_pic FROM user WHERE user_id = '$_SESSION[user_id]' AND profile_pic =' ' ");
	
		if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    	} else {
		$result = $mysqli->query($data);
		$count = $result->num_rows;
		$count != 1? $msg = $_SESSION['picture']=1 : $_SESSION['picture']=0;
		return $_SESSION['picture'];
		}
	}
}
?>
