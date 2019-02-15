	
	var inputFields = document.theform.getElementsByTagName("input");
	
	function validate(){
	
	for (key in inputFields){
	var myField = inputFields[key];
	var myError = document.getElementById("error");	
	//console.log(myField.name);
	
	myField.onchange = function (){
	
	console.log(this.pattern);
	
	var myPattern = this.pattern;
	var myPlaceholder = this.placeholder;
	var isValid = this.value.search(myPattern) >= 0;	
	
	!isValid ? myError.innerHTML = "input does not match expected pattern: " + 					myPlaceholder
				: myError.innerHTML = "";

	}
}
	}