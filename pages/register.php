<?php 
$page_title = "Register";
include 'header.php'; 

$error		= null;

	function __autoload($class_name){
	include '../includes/class.' . $class_name . '.inc';
	}

// checks if user is logged in
if (!isset($_SESSION['user_id'])) {
	
	
    // checks if sign up button is clicked 
    if (isset($_POST['register'])) {
		
        $register = new Register();

        // if all sumbitted data is valid 
        if ($register->process()) {
 		 
		  $error = "Successfully Registered ";
		  $error .= Email::EmailUser("Registration");
		  echo $java ="<script>
          setTimeout(function(){ 
            window.location.href = 'login.php';
        },1500);
        </script>";
         
        } else {
            //else show errors
            $error = $register->showErrors();

        }
    }
} else {
	// Already registered
    $error = 'Already Registered'; 
}

echo ErrorDisplay::DisplayError($error); 
echo "<div class='div-row'>". RegisterDisplay::Display() . "</div>";
include 'footer.php'; 

?>