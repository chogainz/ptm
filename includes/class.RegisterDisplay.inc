<?php 
	/**
	* RegisterDisplay
	*/
    abstract class RegisterDisplay{

       public static function display(){

           $token= $_SESSION['token'] = sha1(uniqid(mt_rand(), true));
	 // assigns vars to posts
           $username = isset($_POST['username']) ? $_POST['username'] : '';
           $password = isset($_POST['password']) ? $_POST['password'] : '';
           $password_confirm = isset($_POST['password_confirm']) ? $_POST['password_confirm'] : '';
           $first_name = isset($_POST['first_name']) ? $_POST['first_name'] : '';
           $last_name = isset($_POST['last_name']) ? $_POST['last_name'] : '';
           $dob = isset($_POST['dob']) ? $_POST['dob'] : '';
           $address = isset($_POST['address']) ? $_POST['address'] : '';
           $postcode = isset($_POST['postcode']) ? $_POST['postcode'] : '';
           $email = isset($_POST['email']) ? $_POST['email'] : '';
  
           $output .= "<div class='navbar-default col-md-6 col-md-offset-3'>";
           $output .= "<form class='form-group'  name='registerForm' action='".$_SERVER['PHP_SELF']."' method='post' >"; 
           $output .= ErrorDisplay::DisplayStrength();
           $output.= "<label>Username </label>";
           $output .= "<input class='form-control' type='text' name='username' required id='username' pattern='[a-zA-Z0-9]{5,16}'   value='".$username."' placeholder='username' class='field' />";
       
           $output.= "<label>Password </label>";
           $output.= "<input class='form-control' type='password' name='password' required id='password' pattern='[a-zA-Z0-9_-]{6,18}' value='".$password."' placeholder='password'  class='field'/>";
      
           $output.= "<label>Confirm</label>";
           $output.= "<input class='form-control' type='password' name='password_confirm' required id='password_confirm' pattern='[a-zA-Z0-9_-]{6,18}' value='".$password_confirm."' placeholder='Confirm password'  class='field'/>";
     
           $output.= "<label>Full Name </label>";
           $output.= "<input class='form-control' type='text' name='first_name' required id='first_name' pattern='[a-zA-Z]{2,22}'  value='".$first_name."' placeholder='joe' class='field'/>";

           $output.= "<input class='form-control' type='text' name='last_name'  required id='last_name' pattern='[a-zA-Z0-9]{2,22}' value='".$last_name."' placeholder='blogs'  class='field'/>";
        
           $output.= "<label>DOB </label>";
           $output.= "<input class='form-control' type='text' name='dob' required id='dob' pattern='[0-9]{2}/[0-9]{2}/[0-9]{4}' value='".$dob."'  placeholder='01/01/1999' class='field'/>";
 
           $output.= "<label>Address </label>";
           $output.= "<input class='form-control' type='text' name='address' required id='address' pattern='[a-zA-Z0-9]{0,3} [a-zA-Z]{2,22} [a-zA-Z]{2,22}' value='".$address."' placeholder='1 Random Road'   class='field'/>";

           $output.= "<label>postcode </label>";
           $output.= "<input class='form-control' type='text' name='postcode' required id='postcode' pattern='[A-PR-UWYZ0-9][A-HK-Y0-9][AEHMNPRTVXY0-9]?[ABEHMNPRVWXY0-9]? {0,2}[0-9][ABD-HJLN-UW-Z]{2}|GIR ?0AA' value='".$postcode."'  placeholder='ST16 1AA' class='field'/>";
       
           $output.= "<label>Email Address </label>";
           $output.= "<input class='form-control' type='text' name='email' required id='email' pattern='[\w-\.]+@([\w-]+\.)+[\w-]{2,4}' value='".$email."' placeholder='sample@sample.com'   class='field'/>";

           $output.= "<input type='hidden'  name='token' value='".$token."'  class='field'/>";
           $output.= "<input class='btn btn-success' type='submit'  name='register' value='Sign up'  class='formButton'/>";

           $output.= "</form>";
      
           return $output;

       }
   }
   ?>