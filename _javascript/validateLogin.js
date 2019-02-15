$(function() {
    if ($("#userBar span").text() !== "") {
        $("#error").css({ "display": "block" }).delay(500).fadeOut(1000);
        $("input[name='login']").val("Logout");

        $("input[name='login']").on("click", function(evt) {

            evt.preventDefault();
             window.location = "logout.php";   
        });

        $(".page-name h3").text("Logout");
    }
});
