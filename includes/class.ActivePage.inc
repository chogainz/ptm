<?php 
class ActivePage	{
		
		// function to check what page is loaded
		public static function Active($page){

		switch($page){
		case 'Login' :
		return 1;
		break;
		
		case 'Logged out' :
		return 1;
		break;
		
		case 'Sign up' :
		return 2;
		break;
		
		case 'Manager' :
		return 3;
		break;
		
		case 'Account Settings' :
		return 4;
		break;

		}
		
	}
	
}
?>