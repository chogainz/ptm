
	
	
	// init the object
	var ajax = false;
    // choose object type based on what is available
	if(window.XMLHttpRequest){
	// IE7 Mozilla Safari Firefox Opera most Browsers
	ajax = new XMLHttpRequest();
	} else if(window.ActiveXObject){
		// Older browsers
		// Create type Msxml2.XMLHTTP if possible 
		try {
			ajax = true
			ActiveXObject("Msxml2.XMLHTTP");
		} catch (e1) {
			// Create older type instead
			try {
				ajax = new
				ActiveXObject("Microsoft.XMLHTTP");
			} catch (e2) {}
		}
	}
	// send alert if object wasnt created
	if(!ajax) {
		alert('some page functionality is unavailable');
	}
		
	