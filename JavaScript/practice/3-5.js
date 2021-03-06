const toDoForm = document.querySelector(".js-toDoform"),
toDoInput = toDoForm.querySelector("input"),
toDoList = document.querySelector(".js-toDoList");

const TODOS_LS = "toDos";

function paintTodo(text)
{
    const li = document.createElement("li");
    const delBtn = document.createElement("button");
    delBtn.innerText = "X";
    const span = document.createElement("span");
    span.innerText = text;
    li.appendChild(delBtn);
    li.appendChild(span);
    toDoList.appendChild(li);
}

function handleSubmit(event)
    {
    event.preventDefault();
    const currentValue = toDoInput.value;
    paintTodo(currentValue);
    toDoInput.value = "";
}

function loadToDos()
{
    const loadedTodos = localStorage.getItem(TODOS_LS);
    if (loadedTodos !== null)
    {
        
    }
}

function init()
{
    loadToDos();
    toDoForm.addEventListener("submit", handleSubmit)
}
init();