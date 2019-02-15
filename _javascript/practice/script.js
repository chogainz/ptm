
function selectTask()
{
var mylist=document.getElementById("List");
mylist = mylist.options[mylist.selectedIndex].text;
console.log(mylist);
document.getElementById("Select").innerHTML ="You Selected Task: " + mylist;

}
function orderProject()
{
var mylist=document.getElementById("Project");
mylist = mylist.options[mylist.selectedIndex].text;
console.log(mylist);
document.getElementById("Order").innerHTML = mylist;

}

window.onload = function(){

};

