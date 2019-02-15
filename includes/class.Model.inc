<?php

/* 
* shared interface for interaction
*/

interface Model {
	/* 
	* loada model
	* @param int $project_id
	*/
  static function loadProject();
  
  static function loadTask($task_id);
	
	/**
	* save a model
	*/
	function save();
	

	
}

?>