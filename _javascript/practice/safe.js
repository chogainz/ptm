

	function validate(fieldName){
	
	var isValid;
	var myError = document.getElementById('error');			
	document.getElementsByName(fieldName)
	
	console.log(fieldName.name);
	
	var getName = fieldName.name;
	
	
	switch(getName){
		
   				case 'first_name':			
				
				isValid = theform[getName].value.search(new RegExp("[a-z]{2}")) >= 0;
				!isValid ? myError.innerHTML = "Invalid first name Must be between 2 and 22 characters" 
				: myError.innerHTML = "";

                break;				
				
				case 'last_name':
				
				isValid = theform[getName].value.search(new RegExp("[a-z]{2}")) >= 0;
				!isValid ? myError.innerHTML += "Invalid first name Must be between 2 and 22 characters" 
				: myError.innerHTML = "";
	
                break;
				
				case 'dob':
				isValid = theform[getName].value.search(new RegExp("[0-9]{2}/[0-9]{2}/[0-9]{4}")) >= 0;
				!isValid ? myError.innerHTML += "Please enter a valid DOB 00/00/0000" 
				: myError.innerHTML = "";
				console.log(fieldName.pattern);
                break;
				
				case 'address':
				
				isValid = theform[getName].value.search(new RegExp("[a-zA-Z0-9]{1}")) >= 0;
				!isValid ? myError.innerHTML += "Invalid Address" 
				: myError.innerHTML = "";
                break;
				
				case 'postcode':
               isValid = theform[getName].value.search(new RegExp("^([A-PR-UWYZ0-9][A-HK-Y0-9][AEHMNPRTVXY0-9]?[ABEHMNPRVWXY0-9]? {0,2}[0-9][ABD-HJLN-UW-Z]{2}|GIR ?0AA)$")) >= 0;
			   !isValid ? myError.innerHTML += "Invalid Postcode | Must be AA11 9AA format" 
				: myError.innerHTML = "";
				console.log(myError);
			   
                break;
				
				case 'email':
                console.log('last_name');
                break;
		}

	}
