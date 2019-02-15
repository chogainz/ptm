<?php ob_start(); ?>
<?php

// starts session and destroys
session_start();
session_destroy();
$page_title = "Logged out";
require("header.php");

function __autoload($class_name) {
    include '../includes/class.' . $class_name . '.inc';
}

?>
<?php 	  $error = "You have been logged out &nbsp<a href='login.php'>Click Here</a>";
		  echo ErrorDisplay::DisplayError($error);
          echo $java ="<script>
          document.getElementById('error').style.display ='block';  
          setTimeout(function(){ window.location.href = 'login.php';},1500)</script>";
?>

<?php echo "</body>" ?>