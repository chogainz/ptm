<?php 
	/**
	* ButtonDisplay
	*/
abstract class ButtonsDisplay implements Display{

	public static function displayAll(){
		   $output = "<div class='navbar-default col-md-6 col-md-offset-3 container'>";
           $output  .= "<form class='form-group' action='".$_SERVER['PHP_SELF']."' method='post' >"; 
		   $output .= "<input class='btn btn-primary' type='submit'  name='all_projects' value='All Projects'  class='formButton'/>";
		   $output .= "<input class='btn btn-success' type='submit'  name='create_project' value='Create Project'  class='formButton'/>";
		   $output .= ProjectDisplay::OrderProjects();
		   $output .= "</form>";
		   $output .= "</div>";
		   return $output;
	}
	
	public static function displayAddTask(){
	
           $output  = "<form  action='".$_SERVER['PHP_SELF']."' method='post' >" ;
		   $output .= "<input class='btn btn-success' type='submit'  name='add_task' value='Add Task'  class='formButton'/>";
		   $output .= "</form>";
		   return $output;
	}

}
?>