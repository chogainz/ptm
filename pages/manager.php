<?php ob_start(); ?>
<?php
$page_title = "Manager";
include("header.php");
function __autoload($class_name){
	include '../includes/class.' . $class_name . '.inc';
}
$error		= null;
$content	= null;

	// checks if user is logged in
!$_SESSION['user_id']? header('Location: check.php'):
$output = ButtonsDisplay::DisplayAll();


if(!$_POST){
	$_SESSION['project_id'] = null;
	$_SESSION['order_tasks'] = 'task_id';
}

if(!isset($_POST['project_id'])){
	$_SESSION['order_projects'] = 'project_id';	
}

// Select a Project
if (isset($_POST['select_project'])) {
	$content = ProjectDisplay::ProjectSelection();
	$output ="";
	
}

	// Select all Projects
if (isset($_POST['all_projects']) || !$_POST) {	
	$content = ProjectDisplay::ProjectCollection();	
}


if (isset($_POST['create_project'])) {

	$content = CreateProjectDisplay::Display();	
	$output ="";
	$page_title = "Create Project";
}


if(isset($_POST['create_new_project'])){	
	$project= new Project();
	if ($project->process()) {	
		$error = 'Project Created';

	} else {

		$error = $project->showErrors();
		$content = CreateProjectDisplay::Display();	
		$output ="";
	}
}



	// Update Project selected
if(isset($_POST['update_project'])){
	$error = ProjectDisplay::ProjectUpdate();
	$content = ProjectDisplay::ProjectSelection();
	$output = "";
	if($error !== "Nothing Updated" && $error !== "invalid submission"){
		$content = ProjectDisplay::ProjectCollection();	
		$output = ButtonsDisplay::DisplayAll();
	}
}

	// Delete a Project
if(isset($_POST['delete_project'])){
	$error = ProjectDisplay::deleteProject();
	
}

	// Order a Project
if(isset($_POST['select_order_projects'])){
	$_SESSION['order_projects']= $_POST['order_projects'];
	$error = "Projects Reordered: " . $_SESSION['order_projects'];
	// replaces the _ in the string
	$error = str_replace ("_", " ", $error);
	$content = ProjectDisplay::ProjectCollection();	
}


	// Create a Task
if (isset($_POST['add_task']) || isset($_POST['create_new_task'])) {
	if(isset($_POST['project_id'])){
		$_SESSION['project_id'] = $_POST['project_id'];
		$output = "";
		$content = CreateTaskDisplay::Display();
	}
	if(isset($_POST['create_new_task'])){
		$task= new Task();
		if ($task->process()) {
			$error = 'Task Added';
			$content = ProjectDisplay::ProjectCollection();	
			$output = ButtonsDisplay::DisplayAll();



		} else {
	//else show errors
			$error = $task->showErrors();
			$content = CreateTaskDisplay::Display();
			$output = "";
		}

	}	
}

	// Select a Task from within a Project
if (isset($_POST['select_task'])) {
	$_SESSION['task_select'] = $_POST['task_clone'];
	$content = TaskDisplay::TaskSelection();
	$output ="";
}
	// Update Selected task from Project
if(isset($_POST['update_task'])){
	$error = TaskDisplay::TaskUpdate();
	$content = TaskDisplay::TaskSelection();
}

	// Delete a Task
if(isset($_POST['delete_task'])){
	$error = TaskDisplay::deleteTask();
}

echo ErrorDisplay::DisplayError($error);
echo "<div class='div-row'>". $output . " " . $content.  "</div>"; 

require("footer.php"); ?>