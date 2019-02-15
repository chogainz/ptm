<?php
// starts session and destroys
session_start();
session_destroy();

?>
<?php
$page_title = "Logged out";
include("header.php");

	function __autoload($class_name) {
    include '../includes/class.' . $class_name . '.inc';
}

		  $error = "You must be Logged in to view this page &nbsp" . "<a href='login.php'>Click Here</a>"; 
	      $error = "<span id='remove_error'>"."$error" ."</span>";
		  echo ErrorDisplay::DisplayError($error);
		  echo $java ="<script>
		  document.getElementById('error').style.display ='block';  
		  setTimeout(function(){ window.location.href = 'login.php';},1500)</script>";
?>
<?php echo "</body>"; ?>
