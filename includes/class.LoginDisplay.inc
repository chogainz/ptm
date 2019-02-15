<?php 
	/**
	* LoginDisplay
	*/
abstract class LoginDisplay{

	private $token;
	
	public static function Display(){

		   $token = $_SESSION['token'] = sha1(uniqid(mt_rand(), true));
		   $output .= "<div class='login-form navbar-default col-md-4 col-md-offset-4'>";
		   $output .=  "<form class='form-group' name='loginForm' action='".$_SERVER['PHP_SELF']."' method='post' >"; 
		   $output .= "<label>Username</label>"; 
		   $output .= "<input class='form-control' type='text' name='username'  required id='username' pattern='[a-zA-Z0-9_-]{5,16}' placeholder='username'  />"; 
	
		   $output .= "<label>Password</label>"; 
           $output .= "<input class='form-control' type='password' required id='password' name='password' pattern='[a-zA-Z0-9_-]{6,18}' placeholder='password' />"; 
		
		   $output .= "<input type='hidden' name='token' value='".$token."' />"; 
		   $output .= "<input class='btn btn-primary' type='submit' name='login' value='Login' class='formButton'/>";
		   $output .= "</form>";  
		   $output .= "</div>"; 
		   return $output;
	}
}
?>