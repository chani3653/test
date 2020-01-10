if("10" === 10)
{
    console.log("hi");
}
else if ( 10 === 10)
{
    console.log("lalala");
}
else 
{
    console.log("ho");
}

if ( 20 > 5 && "nicolas" === "nicolas")
{
    console.log("yes");
}
else
{
    console.log("no");
}

const age = prompt (" How Old are you?");
if( age >= 18 && age <=21)
console.log( " you can drink but you should not");
else if (age > 21)
console.log("you can drink")
else
console.log(" too young ");


const title =document.querySelector("#title");
function handleClick()
{
    title.style.color = "red";
}

title.addEventListener("click",handleClick);
