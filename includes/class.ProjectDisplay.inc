<?php 
	/**
	* projectDisplay
	*/
abstract class ProjectDisplay implements Display{
	
	
	public static function ProjectCollection(){
	
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	$output = null;
    // query is select all from users where ID equals session ID
    $data = ("SELECT * FROM project WHERE user_id ='{$_SESSION['user_id']}' ORDER BY {$_SESSION['order_projects']} ");	
	// if cant query display error message and mysql error
	if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
	$result = $mysqli->query($data);	
	$rows = array();
    while($row = $result->fetch_assoc()) {
    $rows[] = $row;
	}
	foreach($rows as $key=> $value){
	$output .= ProjectDisplay::DisplayProjectTitle($value);
	
			}
		}
	return $output;
}
		
	public static function DisplayProjectTitle($project){
		  $output = "<div class='navbar-default col-md-6 col-md-offset-3 container'>";
		   $output  .= "<form class='form-group'  action='".$_SERVER['PHP_SELF']."' method='post' >"; 
		   $output .= "<label>Project Title</label>";
		   $output .= "<input class='form-control' type='text' name='project_id' value='".$project['project_title']."'  readonly='readonly' class='field'/>";
		   $output .= "<br/>";
		   $output .= "<label>Project Created</label>";
		   $output .= "<input class='form-control' type='text' name='project_id' value='".$project['project_created']."'  readonly='readonly' class='field'/>";
		   $output .= "<br/>";
		   $output .= "<input type='hidden' name='project_id' value='".$project['project_id']."'  class='field'/>";
		   $output .= "<input type='hidden' name='project_title' value='".$project['project_title']."'  class='field'/>";
		   $output .= "<input class='btn btn-primary' type='submit'  name='select_project' value='View'  class='formButton'/>";
           $output .= "<input class='btn btn-warning' type='submit'  name='delete_project' value='Delete'  class='formButton'/>";
		   $output .= "<input class='btn btn-success' type='submit'  name='add_task' value='Add Task'  class='formButton'/>";
		   $output .= "</form>";
           $output .= "</div>";
		   
		   return $output;
	}
	
	public static function DisplayProject($project){		
	 		
	
			$token = $_SESSION['token'] = sha1(uniqid(mt_rand(), true));
			$_SESSION['check'] = $project['project_completed'];
            $output = "<div class='navbar-default col-md-6 col-md-offset-3'>";
			$output  .= "<form class='form-group'  action='".$_SERVER['PHP_SELF']."' method='post' >";  
			$output .= "<label>Title: </label>";
            $output .= "<input class='form-control' type='text' name='project_title' value='".$project['project_title']."' class='field'/>";
      		$output .= "<br/>";
			$output .= "<label>Description </label>";
			$output .="<textarea class='form-control' cols='40' rows='5' name='project_description'>".$project['project_description']."</textarea>";
      		$output .= "<br/>";
			$output .= "<label>Completed </label>";
			if($_SESSION['check']== 1){
			$output .= "<input class='form-control' type='checkbox' name='project_completed' checked='checked'  value='".$project['project_completed']."'  class='field'/>";
			$output .= "<span>".$project['project_modified']."</span>";	
			}
			if($_SESSION['check']== 0){
			$output .= "<input class='form-control' type='checkbox' name='project_completed'  value='".$project['project_completed']."'  class='field'/>";	
			}
            $output .= "<label>Modified </label>";
			$output .= "<input class='form-control' type='text' name='project_modified' value='".$project['project_modified']."' class='field'/>";
			$output .= "<label>Created </label>";
            $output .= "<input class='form-control' type='text' name='project_created' value='".$project['project_created']."'  class='field'/>";
			$output .= "<br/>";
			$output .="<input type='hidden' name='project_id' value='".$project['project_id']."'  class='field'/>";
			$output .= "<input type='hidden' name='token' value='".$token."'  class='field'/>";
            $output .= "<input class='btn btn-primary' type='submit'  name='update_project' value='Update'  class='formButton'/>";
            $output .= "<input class='btn btn-warning' type='submit'  name='delete_project' value='Delete'  class='formButton'/>";
			$output .= "<input class='btn btn-primary' type='submit'  name='add_task' value='Add Task'  class='formButton'/>";
			
			$output .= "</form>";
            $output .= "</div>";
			
			return $output;
	}
	
	
	
	
	public static function ProjectSelection(){
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	$_SESSION['project_id']=$_POST['project_id'];
    // query is select all from users where ID equals session ID
    $data = ("SELECT * FROM project WHERE project_id ='{$_SESSION['project_id']}'");	
	// if cant query display error message and mysql error
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
		$result = $mysqli->query($data);	
		$result = $result->fetch_assoc();
		$output  = ProjectDisplay::DisplayProject($result);
		$output .= TaskDisplay::TaskCollection();
		return $output;
	}
}
	
	

	
	public static function ProjectUpdate(){
	$update = new UpdateProject();
	$output = null;
    // if no errors updates
        if ($update->process()) {
            // sets user details	
              $output = 'Project Updated';
        } else {
        //else show errors
    $output = $update->showErrors();
	}
	
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	
    // query is select all from users where ID equals session ID
    $data = ("SELECT * FROM project WHERE project_id ='{$_SESSION['project_id']}'");
		
	// if cant query display error message and mysql error
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
		$result = $mysqli->query($data);	
		$result = $result->fetch_assoc();

		}	
		return $output;
	}

	public static function deleteProject(){
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	$_SESSION['project_select'] = $_POST['project_id'];
    $data = ("DELETE FROM project WHERE project_id ='{$_SESSION['project_select']}'");
	TaskDisplay::deleteTask();
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
		if(isset($_POST['project_title'])){
		$_SESSION['project_select'] = $_POST['project_title'];
		}
		$result = $mysqli->query($data);	
		$output = 'Project: ' . $_SESSION['project_select'] . " and all Tasks" .  ' Deleted';
			}
			return $output;
		}
	
	
	public static function OrderProjects(){		
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
			 // query is select all from users where ID equals session ID
    $data = ("SELECT project_title, project_created FROM project LIMIT 1 ");	
	// if cant query display error message and mysql error
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
	$result = $mysqli->query($data);
	$rows = array();
	$output=null;
    while($row = $result->fetch_assoc()) {
    $rows[] = $row;


	$output .="<select class='form-control' name='order_projects' id='Project'>";

    foreach($row as $key=> $value){
	$output .="<option value='".$key."'  selected='selected' > ".str_replace ("_", " ", $key)."</option>";
			}
	$output .="</select>";
	$output .= "<input class='btn btn-primary' type='submit'  name='select_order_projects' value='Order'  class='formButton'/>";

				
				}

	return $output;
			}
		}
	
}
?>