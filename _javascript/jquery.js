$(document).ready(function(){
	$(loginForm).submit(function(){
		var abort =false;
		$("div.error").remove();
		$(':input[required]').each(function(){
          if($(this).val()===''){
			$(this).after('<div class="error"><h3>This field is Required</h3></div>');  
		  abort = true;
		  }
		}); // go through each required value
		if(abort){return false; } else { return true; }
	}) // on submit
}); // ready

	$(':input[placeholder]').blur(function(){
	$("div.error").remove();
	var myPattern = $(this).attr('pattern');
	var myPlaceholder = $(this).attr('placeholder');	
	var isValid = $(this).val().search(myPattern) >= 0; 
	
	if(!isValid){
		$(this).focus();
		$(this).after('<div class="error"><h3>Invalid Input</h3></div>');
	} // isValid text
}); // onblur

