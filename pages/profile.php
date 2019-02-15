<?php ob_start(); ?>
<?php
$page_title = "Account Settings";
include("header.php");
$user = null;
$logout = null;
$error = null;

function __autoload($class_name) {
    include '../includes/class.' . $class_name . '.inc';
}

// Checks if user is logged in
if (!$_SESSION['user_id']) {
    header('Location: check.php');
} else {
    // Checks if user exists
    if (isset($_SESSION['user_id'])) {
		
		$error = Upload::UploadImage();

        // checks if update button has been clicked
        if (isset($_POST['update'])) {
            $update = new UpdateProfile();
			
            // if no errors updates
            if ($update->process()) {
                // sets user details	
 
		  $error = "Updated "; 
		  $error .= Email::EmailUser("Profile Updated");
		  
			} else {
		  
		  $error  = $update->showErrors();
          //else show errors
                
            }
        }
        $db = Database::getInstance();
        $mysqli = $db->getConnection();
        // query is select all from users where ID equals session ID
        $data = ("SELECT * FROM user WHERE user_id ='{$_SESSION['user_id']}'");
        // if cant query display error message and mysql error
        if (!$data) {
            die("Databases query failed:<br /> " . mysqli_error());
        } else {

            $result = $mysqli->query($data);
            $result = $result->fetch_assoc();
        }
    }
}
// checks if update button has been clicked
if (isset($_POST['delete'])) {

    $db = Database::getInstance();
    $mysqli = $db->getConnection();

    // query is select all from users where ID equals session ID
    $data = ("DELETE FROM user WHERE user_id ='{$_SESSION['user_id']}'");
    // if cant query display error message and mysql error

    $result = $mysqli->query($data);
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
        
    $error =   "Profile Deleted" ;
	header('Location: check.php');
    }
}

echo ErrorDisplay::DisplayError($error);
echo "<div class='div-row'>". FileUploadDisplay::Display("file")  . " " . ProfileDisplay::Display($result) . "</div>"; 
require("footer.php"); ?>