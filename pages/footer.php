
</div>
<footer class="footer" id="footer">
    Project | Task | Manager © 2016
</footer>
<?php
if($page_title == "Login"){ echo '<script type="text/javascript" src="../_javascript/validateLogin.js"></script>';}
if($page_title == "Register"){echo '<script type="text/javascript" src="../_javascript/validateRegister.js"> </script>';}
if($page_title == "Account Settings"){echo'<script type="text/javascript" src="../_javascript/validateUpdate.js"> </script>';}
if($page_title == "Manager"){echo'<script type="text/javascript" src="../_javascript/validateManager.js"> </script>';}
?>
</body>
<script type="text/javascript">


    $(window).resize(function() {

        $(".page-name").css({"left": (($(".navbar").width()/2) - ($(".page-name").width()/2)) + "px" });
        $("#error").css({"top": ($(".navbar").outerHeight()-1) + "px" });
    });

    $(function(){

        $(".page-name").css({"left": (($(".navbar").width()/2) - ($(".page-name").width()/2)) + "px" });
        $("#error").css({"top": ($(".navbar").outerHeight()-1) + "px" });

        if ($("#userBar span").text() !== "") {
            $(".login a").replaceWith("<a href='logout.php'>Logout</a>");
            $(".register a").replaceWith("<a href='profile.php'>Account Settings</a>");
        }

        setTableHeight(10, ".navbar",".footer",".div-row");    
    });

    function setTableHeight(margin, header,footer,row){
        var marginVertical =   margin + "px";
        var headerHeight = $(header).outerHeight();
        var footerHeight = $(footer).outerHeight();
        var rowHeight = $(row).height();
        var NavFooter =  headerHeight + footerHeight;
        var tableHeight = rowHeight - ((margin * 2) + (NavFooter)) + "px";

        $(".div-table").css({
            "height": tableHeight,
            "margin-top":    "+=" + margin,
            "margin-bottom": "+=" + margin,
        });
    }


</script>
</html>
<!-- Footer page gets included -->
<?php
// if connection is set Close connection
if (isset($connection)) {
    mysql_close($connection);
}
?>
