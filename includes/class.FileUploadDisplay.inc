<?php

/**
 * profilePersonal
 */
abstract class FileUploadDisplay implements Display {

    private $token;

    public static function Display($picture) {

                $output .= "<div class='navbar-default col-md-6 col-md-offset-3'>";
                $output .= "<form class='form-group' name='fileForm' action='" . $_SERVER['PHP_SELF'] ."' method='post' enctype='multipart/form-data' >";
				$output .= "<label for='profile_pic' >Picture</label>";
				$output .="<input class='form-control' type='file'  name='profile_pic' id='profile_pic' accept=image/jpg' />"; 
                $output .= "<input class='btn btn-success'  type='submit' name='change' value='Change'  class='formButton'/>";
				$output .= "</form>";
            
				return $output;
    }

}

?>