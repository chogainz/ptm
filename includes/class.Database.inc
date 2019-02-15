<?php
/**
* MySQLi database; only one connection is allowed
*/
class Database{
	private $_connection;	
	// store the single instance
	private static $_instance;
	
	/**
	* Get instance of the Database
	* @return Database
	*/
	public static function getInstance(){
		if(!self::$_instance){
			self::$_instance = new self(); 
		}
		return self::$_instance;
	}
	/**
	* Constructor
	*/
	public function __construct(){
		$this->_connection = mysqli_connect('db658819889.db.1and1.com',
			'dbo658819889', 'webmaster16', 'db658819889');
	// error handling
		if(mysqli_connect_error()){
			trigger_error('Failed to connect to MySQLi:' . mysqli_connect_error(), E_USER_ERROR);	
		}
	}
	
	/**
	* Empty clone magic method to prevent connection
	*/
	private function __clone(){

	}
	/**
	* get MySQLi connection
	*/
	public function getConnection(){
		return $this->_connection;
	}
}
