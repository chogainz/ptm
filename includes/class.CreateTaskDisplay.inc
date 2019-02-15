<?php 
	/**
	* RegisterDisplay
	*/
abstract class CreateTaskDisplay{

	public static function display(){
	
	 $title = isset($_POST['task_title']) ? $_POST['task_title'] : '' ;
     $description = isset($_POST['task_description']) ? $_POST['task_description'] : '' ;
	 $token= $_SESSION['token'] = sha1(uniqid(mt_rand(), true));
	         $output = "<div class='navbar-default col-md-6 col-md-offset-3 container'>";
			 $output .= "<form class='form-group'  action='".$_SERVER['PHP_SELF']."' method='post' >";
			 $output.= "<label>Task Title </label>";
             $output.= "<input class='form-control' type='text' name='task_title'  value='".$title."'  class='field' />";
			 $output.= "<br/>";
             $output.= "<label>Task Description </label>";
             $output.= "<textarea class='form-control' cols='40' rows='5'  name='task_description'>".$description."</textarea>";
             $output.= "<br/>";
			 $output.= "<input type='hidden'  name='token' value='".$token."'  class='field'/>";
			 $output.= "<br/>";
             $output.= "<input class='btn btn-primary' type='submit' id='create_btn'  name='create_new_task' value='Create'  class='formButton'/>";
			 $output.= "</form>";
             $output .= "</div>";
  			 return $output;
	}
	
	
}
?>