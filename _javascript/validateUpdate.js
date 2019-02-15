$(function() {

    $(document).ready(function() {
    $("input[type='file']").change(function(evt) {
     url = this;
     $("input[name='change']").on("click", function(){
        readURL(url);
     });
    });
});

function readURL(input) {
    if (input.files && input.files[0]) {
        var reader = new FileReader();

        reader.onload = function (e) {
            $('img').attr('src', e.target.result);
        }

        reader.readAsDataURL(input.files[0]);
    }
}

    $(".top-break").css({"height" : "100px"});
    if ($("#error").text() !== "") {
        $("#error").css({ "display": "block" }).delay(500).fadeOut(1000);
    } 
});
