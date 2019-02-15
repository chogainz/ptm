<?php	
    /**
	* ErrorDisplay
	*/
	abstract class ErrorDisplay {

		private $error;

		public static function DisplayError($error) {
			return "<div id='error'>". $error. "</div>";
		}


		public static function DisplayStrength() {
			return "<span id='strengthBar'></span>";
		}


		public static function DisplayUser($page, $login, $user){
			return "<div id='userBar'><a href='".$page.".php'>".$login. "</a>" . "<span>" .$user. "</span>" . "</div>";
		}
		
	// function to clear errors
		public static function ClearError() {

				return "<script type='text/javascript'>
				setInterval(function(){
					var deleteText = document.getElementById('error');
					deleteText.style.visibility='hidden';  
				},2000);</script>";
			}
		}
?>