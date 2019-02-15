<?php session_start(); ?>
<?php 

$login		= "";
$register	= "";
$manager	= "";
$profile	= "";
$selected = "active";

switch($page_title){
	case "Login" :
	$login = $selected;
	break;
	case "Register" :
	$register = $selected;
	break;
	case "Manager" :
	$manager = $selected;
	break;
	case "Account Settings" :
	$register = $selected;
	break;
}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title><?php echo $page_title; ?></title>
  <link href="../stylesheet/public.css" media="all" rel="stylesheet" type="text/css" />
  <script type="text/javascript" src="../_javascript/jquery-3.1.1.min.js"></script>
  <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

  <!-- Optional theme -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">

  <!-- Latest compiled and minified JavaScript -->
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</head>
<body>

  <nav class="navbar navbar-inverse"">
    <div class="container-fluid">
      <div class="nav navbar-nav">
        <a class="<?php echo 'navbar-brand login ' . $login  ?>" href="login.php">PTM</a>
      </div>
      <ul class="nav navbar-nav">
        <li class="<?php echo 'register '  .  $register ?>"><a href="register.php">Register</a></li>
        <li class="<?php echo 'manager ' . $manager  ?>"><a href="manager.php">Manager</a></li>
      </ul>    


      <?php

		// checks if user is logged in
      if(isset($_SESSION['user_id'])){
        Upload::CheckPic();
	   // checks if the user already has a profile picture
        echo $_SESSION['picture']==1?" 
        <img  src='../_uploads/profile_pic_".$_SESSION['user_id'].
        '.jpg'."' alt='profile_pic'/>" : 
        "<img src='../_images/profile_pic.png'  alt='profile_pic'/>";
      } else { 
        echo "<img src='../_images/profile_pic.png'  alt='profile_pic'/>";
      }?> 

      <?php 
		// checks if username exists and assigns title
      echo isset($_SESSION['username'])? ErrorDisplay::DisplayUser("logout" ," Logout &nbsp" , $_SESSION['username'])
      : ErrorDisplay::DisplayUser("login" , "Login",""); ?>  

    </div>
  </div>
</nav>     
<div class="div-table container-fluid">
    <div class="page-name"><h3 ><?php echo $page_title; ?></h3></div>     
