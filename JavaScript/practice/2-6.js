const title = document.querySelector("#title");

const BASE_COLOR = "rgb(52, 73, 94)";
const OTHER_COLOR = "#7f8c8d";

function handleClick()
{
    const currentColor = title.style.color;
    if (currentColor === BASE_COLOR) 
    {
        title.style.color = OTHER_COLOR;
    }
    else 
    {
        title.style.color = BASE_COLOR;
    }
}

function init()
{
    title.style.color = BASE_COLOR;
    title.addEventListener("mouseenter",handleClick);
}
init();
/*
function handleoffline()
{
    console.log("ByeBye");
}
function handleonline()
{
    console.log("Welcome Back!");
}
window.addEventListener("offline", handleoffline);
window.addEventListener("online", handleonline);
*/