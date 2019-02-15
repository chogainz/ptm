<?php 
	/**
	* taskDisplay
	*/
abstract class TaskDisplay implements Display{

	public static function DisplayTask($task){
	
						
						$token = $_SESSION['token'] = sha1(uniqid(mt_rand(), true));		
	                    $_SESSION['check'] = $task['task_completed'];
                        $output = "<div class='navbar-default col-md-6 col-md-offset-3'>";
						$output  .= "<form class='form-group'  action='".$_SERVER['PHP_SELF']."' method='post' >";  
						$output .= "<label>Task Title </label>";
                        $output .= "<input class='form-control' type='text' name='task_title' value='".$task['task_title']."' class='field'/>";
						$output .= "<label>Description </label>";
						$output .= "<br/>";
						$output .= '<textarea class="form-control" cols="40" rows="5" name="task_description">'.$task['task_description'].'</textarea>';
						$output .= "<label>Completed </label>";
                        if($_SESSION['check']== 1){
						$output .= "<input class='form-control' type='checkbox' name='task_completed' checked='checked'  value='".$task['task_completed']."'  class='field'/>";
						$output .= $task['task_modified'];	
						}
						if($_SESSION['check']== 0){
						$output .= "<input class='form-control' type='checkbox' name='task_completed'  value='".$task['task_completed']."'  class='field'/>";	
						}
						$output .= "<label>Modified </label>";
                        $output .= "<input class='form-control' type='text' name='task_modified' value='".$task['task_modified']."' class='field'/>";
						$output .= "<label>Created </label>";
            			$output .= "<input class='form-control' type='text' name='task_created' value='".$task['task_created']."' class='field'/>";
						$output .= "<input type='hidden' name='task_id' value='".$task['task_id']."'  class='field'/>";
						$output .= "<input type='hidden' name='token' value='".$token."'  class='field'/>";
                        $output .= "<input class='btn btn-primary' type='submit'  name='update_task' value='Update'  class='formButton'/>";
                        $output .= "<input class='btn btn-warning' type='submit'  name='delete_task' value='Delete'  class='formButton'/>";
						$output .= "</form>";
                        $output .= "</div>";
						return $output;
	}
		
		
	public static function TaskCollection(){
	
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	$output = null;
			 // query is select all from users where ID equals session ID
    $data = ("SELECT * FROM task WHERE project_id ='{$_SESSION['project_id']}' ORDER BY {$_SESSION['order_tasks']}");	
	// if cant query display error message and mysql error
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
	$result = $mysqli->query($data);
	$rows = array();
	$value =null;
    while($row = $result->fetch_assoc()) { 
	$rows[] = $row;
    $output = "<div class='navbar-default col-md-6 col-md-offset-3'>";
	$output .= "<form class='form-group' action='".$_SERVER['PHP_SELF']."' method='post' >";
	
	
	$output .="<input class='btn btn-primary' type='submit'  name='select_task' value='Select Task'  class='formButton'/>";
	$output .="<input class='btn btn-warning' type='submit'  name='delete_task' value='Delete Task'  class='formButton'/>";
	$output .="<select class='form-control' name='task_clone'  id='List' onchange='selectTask(this.value)'>";
	foreach($rows as $key=> $value){
	$output .="<option value='".$value['task_id']."' selected='selected' >  ".$value['task_title']. " : " . $value['task_created']. "</option>";
			}
	$output .="</select>";
	$output .= TaskDisplay::OrderTasks();
	$output .="</form>";
    $output .= "</div >";
	
				}
				
		return $output;
			}

		}
		
		
	public static function TaskUpdate(){
	$update = new UpdateTask();
	$output = null;
    // if no errors updates
        if ($update->process()) {
            // sets user details
	$output = "Task Updated";
        } else {
    //else show errors
   $output = $update->showErrors();
   
	}
	return $output;
}
		
			
	public static function TaskSelection(){
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
    $data = ("SELECT * FROM task WHERE task_id ='{$_SESSION['task_select']}'");	
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
		$result = $mysqli->query($data);	
		$result = $result->fetch_assoc();
		$output = TaskDisplay::DisplayTask($result);
		return $output;
	}
}
	
	public static function deleteTask(){
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
	$_SESSION['task_select'] =null;
	if(isset($_POST['task_id'])){
	$_SESSION['task_select'] = $_POST['task_id'];
    $data = ("DELETE FROM task WHERE task_id ='{$_SESSION['task_select']}'");	
	}
	if(isset($_POST['task_clone'])){
	$_SESSION['task_select'] = $_POST['task_clone'];
    $data = ("DELETE FROM task WHERE task_id ='{$_SESSION['task_select']}'");	
	}
	if(isset($_SESSION['project_select'])){
    $data = ("DELETE FROM task WHERE task_id ='{$_SESSION['task_select']}'");	
	}
	if(!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {

		if(isset($_POST['task_title'])){
		$_SESSION['task_select'] = $_POST['task_title'];
		}
		$result = $mysqli->query($data);
		$output = 'Task: ' . $_SESSION['task_select'] . ' Deleted';
	
			}
	return $output;	
}
	

	public static function PasteTask(){
	
	if(isset($_SESSION['task_clone'])){
	$update = new CloneTask();
    // if no errors updates
        if ($update->process()) {
            // sets user details	
   
		$output= 'Task Pasted';
		unset($_SESSION['task_clone']);
        } else {
		// errors	
		}
		return $output;
	}
}


	
	public static function OrderTasks(){		
	$db = Database::getInstance();
    $mysqli = $db->getConnection();
			 // query is select all from users where ID equals session ID
    $data = ("SELECT task_title, task_created FROM task ");	
	// if cant query display error message and mysql error
    if (!$data) {
        die("Databases query failed:<br /> " . mysqli_error());
    } else {
	$result = $mysqli->query($data);
	$rows = array();
    while($row = $result->fetch_assoc()) {
    $rows[] = $row;
	$output ="<select class='form-control' name='order_tasks' id='Project' >";
	foreach($row as $key=> $value){
	$output .="<option value='".$key."'  selected='selected' > ".str_replace ("_", " ", $key)."</option>";
			}
	$output .="</select>";
	$output .= "<input class='btn btn-primary' type='submit'  name='select_order_tasks' value='Order'  class='formButton'/>";
				
				}
	return $output;
			}
		}


}

?>