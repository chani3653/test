const nicoInfo = {
    name : "nico",
    age :33,
    gender:"male",
    isHandsome: true
}
console.log(nicoInfo, console)

function sayHello(name, age)
{
    return (`Hello ${name} You are ${age} years old`);
}

const greetNicolas = sayHello("Nicolas", 14)
console.log(greetNicolas)
