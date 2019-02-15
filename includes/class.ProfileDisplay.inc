<?php

/**
 * profilePersonal
 */
abstract class ProfileDisplay implements Display {

    private $token;

    public static function Display($profile) {


       			$token = $_SESSION['token'] = sha1(uniqid(mt_rand(), true));
               
                $output = "<form class='form-group'  name='updateForm' action='" .$_SERVER['PHP_SELF']. "'  method='post' >";
				$output .= "<label>Full Name </label>";
                $output .= "<input class='form-control'  type='text'  name='first_name'  id='first_name' pattern='[a-zA-Z]{2,22}' value='" . $profile['first_name'] . "' class='field'/>";
                $output .= "<input class='form-control'  type='text'  name='last_name'   id='last_name' pattern='[a-zA-Z]{2,22}'  value='" . $profile['last_name'] . "'  class='field'/>";
                $output .= "<br/>";
                $output .= "<label>DOB </label>";
                $output .= "<input class='form-control'  type='text' name='dob'  pattern='[0-9]{2}/[0-9]{2}/[0-9]{4}'  value='"  . $profile['dob'] . "' class='field'/>";
                $output .= "<br/>";
                $output .= "<label>Address </label>";
                $output .= "<input class='form-control' type='text' name='address'  pattern='[a-zA-Z0-9]{0,3} [a-zA-Z]{2,22} [a-zA-Z]{2,22}'  value='" . $profile['address'] . "'  class='field'/>";
                $output .= "<br/>";
                $output .= "<label>Postcode </label>";
                $output .= "<input class='form-control'  type='text' name='postcode' pattern='[A-PR-UWYZ0-9][A-HK-Y0-9][AEHMNPRTVXY0-9]?[ABEHMNPRVWXY0-9]? {0,2}[0-9][ABD-HJLN-UW-Z]{2}|GIR ?0AA'  value='" . $profile['postcode'] . "' class='field'/>";
                $output .= "<br/>";
                $output .= "<label>Email Address </label>";
                $output .= "<input class='form-control'  type='text' name='email'  pattern='[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$' value='" . $profile['email'] . "' class='field'/>";
                $output .= "<br/>";
                $output .= "<input type='hidden'  name='token' value='" . $token . "'  class='field'/>";
                $output .= "<input class='btn btn-success' type='submit'  name='update' value='Update'  class='formButton'/>";
                $output .= "<input class='btn btn-warning'  type='submit'  name='delete' value='Delete Account'  class='formButton'/>";
				$output .= "</form>";
                $output .= "</div>";
				return $output;
    }

}

?>