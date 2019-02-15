<?php
// creates a private class
class UpdateTask {

    // creates private variables
    private $_task_title;
    private $_Project_description;
    private $_task_completed;
	private $_task_id;

	
	//constructor method assigns the private variables
    public function __construct() {
        //errors var empty array
        $this->_errors = array();

        // filters the posts for submitted data
        $this->_task_title = $this->filter($_POST['task_title']);
        $this->_task_description = $this->filter($_POST['task_description']);
        $this->_task_completed = isset($_POST['task_completed']) ? 1 : 0;

        // assings token var to post
        $this->_token = $_POST['token'];

    }

    // process function checks all validation
    public function process() {
        // if token is valid and data is valid call register function
        if ($this->isTokenValid() && $this->isDataValid())
            $this->Update();

        return count($this->_errors) ? 0 : 1;
    }

    public function filter($var) {
        // includes special chars when matched and stops sql injection
		return preg_replace('/[^-a-zA-Z0-9@. \/]/', '', $var);
    }

    //verify data against database
    public function Update() {
       		// DB connection
		$db = Database::getInstance();
    	$mysqli = $db->getConnection();  
	    //inserts username and password in to users table
         $data = ("UPDATE task SET
							task_title='{$this->_task_title}',
                            task_description='{$this->_task_description}', 
                            task_completed='{$this->_task_completed}'
							WHERE task_id ='{$_SESSION['task_select']}' ");
			$result = $mysqli->query($data);
        if ( $mysqli->affected_rows < 1)
        // checks if data has been succesfully inputed
            $this->_errors[] = 'Nothing Updated';
    }

    //verify data is valid
    public function isDataValid() {
    if (empty($this->_task_title) || !preg_match('/^[a-zA-Z0-9 ]{1,22}$/', $this->_task_title))
            $this->_errors[] = 'Title must be 22 characters max';
        else if (empty($this->_task_description) || !preg_match('/^[a-zA-Z0-9 ]{1,200}$/', $this->_task_description))
            $this->_errors[] = 'Description must be 200 characters max';
        // return true or false 
        return count($this->_errors) ? 0 : 1;
    }

    //check if the form submission is valid
    public function isTokenValid() {
        if (!isset($_SESSION['token']) || $this->_token != $_SESSION['token'])
            $this->_errors[] = 'invalid submission';

        // return true or false 
        return count($this->_errors) ? 0 : 1;
    }

    //displays errors that occur during processing of the form
    public function showErrors() {
     
        
        foreach ($this->_errors as $key => $value)
            $this->_errors = $value;
			return $this->_errors;
    }

}

?>
