<?php ob_start(); ?>
<?php 
$page_title = "Login";
include "header.php"; 

function __autoload($class_name) {
    include "../includes/class." . $class_name . ".inc";
}

$logout	= null;
$error	= null;
$user	= null;


if (!isset($_SESSION["user_id"])) {

	if (isset($_POST["login"])) {

        $login = new Login();

        // if no errors load content page
        if ($login->isLoggedIn())
            header("Location: manager.php");
        else
       
        // else show errors
        $error = $login->showErrors();
    }
} else {

    $error = "Already Logged In";
}

echo "<div class='div-row'>". LoginDisplay::Display() . "</div>"; 
echo ErrorDisplay::DisplayError($error);  
include "footer.php"; 

?>