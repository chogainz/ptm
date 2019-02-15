	//console.log("validate loaded");
	var loginInputFields = document.loginForm.getElementsByTagName('input');
	var myError = document.getElementById('error');	
	var myPattern;
	var myPlaceholder
	var isValid;
	
	// for older browsers
	var validateLogin = {
			
	"username" : {
	"pattern" : "[a-z0-9_-]{5,12}",
	"placeholder" : "username",
	"required" : true },
	
	"password" : {
	"pattern" : "[a-z0-9_-]{6,18}",
	"placeholder" : "password",
	"required" : true },
	
	};
	

		document.loginForm.onsubmit = function(){
		if(Modernizr.input.required){
		for(key in validateLogin){
		var myField = document.getElementById(key);
		if((!validateLogin[key].required)){
		alert(key);
		myError.innerHTML = "Required Field " + key + " not Filled";  
		myField.select();  
		return false;
			}// required field empty
		}// check validation
		return true;	
	}
}
	
	
	/* loops through all the fields
	making the elements available... name pattern etc	
	*/
	for(key in loginInputFields){
	
	var myField = loginInputFields[key];

	myField.onchange = function(){

	
	// checks if browser allows patterns
	if(Modernizr.input.pattern){ 
	myPattern = this.pattern; 
	myPlaceholder = this.placeholder;
	}else{
	myPattern = validateLogin[this.name].pattern;
	myPlaceholder = validateLogin[this.name].placeholder; 
	}
	
	// start of switch statement
	switch(this.name){
		
				case 'username':
				isValid = loginForm[this.name].value.search(myPattern) >= 0;
			   !isValid ? myError.innerHTML = "Please provide a valid username"
				: myError.innerHTML = "";
     			break;
				
				case 'password':
				
				isValid = loginForm[this.name].value.search(myPattern) >= 0;
			   !isValid ? myError.innerHTML = "Please provide a valid password" 
				: myError.innerHTML = "";
     			break;
			}
		}
	}
