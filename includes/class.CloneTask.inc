<?php
// creates a private class
class CloneTask {

    // creates private variables
    private $_task_title;
    private $_Project_description;
    private $_task_completed;
	private $_task_id;
	private $_task_clone;

	
	//constructor method assigns the private variables
    public function __construct() {
        //errors var empty array
        $this->_errors = array();

		$this->_task_clone = $_SESSION['task_clone'];

    }

    // process function checks all validation
    public function process() {
        // if token is valid and data is valid call register function
         $this->TaskClone();

        return count($this->_errors) ? 0 : 1;
    }

    public function filter($var) {
        // includes special chars when matched and stops sql injection
		return preg_replace('/[^-a-zA-Z0-9@. \/]/', '', $var);
		}

	//verify data against database
    public function TaskClone() {
       	// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();  
		 
		 
		$data = ("SELECT * FROM  task WHERE task_id ='{$this->_task_clone}' ");
		 
		$result = $mysqli->query($data);
		$result = $result->fetch_assoc();
							
		$data = ("INSERT INTO task (task_title,task_description,task_created,task_completed,task_modified,project_id)
                            VALUES ('{$result['task_title']}',
                           '{$result['task_description']}',
                           '{$result['task_created']}',
						   '{$result['task_completed']}',
                           '{$result['task_modified']}',
						   '{$_SESSION['project_id']}')");
						   
		$result = $mysqli->query($data);
       if ( $mysqli->affected_rows < 1)
        // checks if data has been succesfully input
            $this->_errors[] = 'Nothing Updated';
	}

    //displays errors that occur during processing of the form
    public function showErrors() {
     
        
        foreach ($this->_errors as $key => $value)
            $this->_errors = "$value";
			return $this->_errors;
    }

}

?>
