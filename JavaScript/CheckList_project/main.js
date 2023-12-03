init();

function init(){
    document.querySelector('form').addEventListener('submit', addToDo);
    document.getElementById('clear').addEventListener('click', clearTodoList);
    document.querySelector('ul').addEventListener('click',deleteOrCheck);
}

function addToDo(e){
    e.preventDefault();
    let toDoValue = document.querySelector('input');
    if(toDoValue.value !== ''){
        addTask(toDoValue.value);
        toDoValue.value='';
    }
}

function deleteOrCheck(e){
    if(e.target.className == 'delete'){
        deleteToDo(e);
    }
    else{
        checkToDo(e);
    }
}

function deleteToDo(e){
    let remove = e.target.parentNode;
    let parentNode = remove.parentNode;
    parentNode.removeChild(remove);
}

function checkToDo(e){
    const todo = e.target.nextSibling;
    if(e.target.checked){
        todo.style.color = "#dddddd";
    }
    else{
        todo.style.color = "#000000";
    }
}

function clearTodoList(){
    
}

function deleteOrCheck(){

}

function addTask(value){
    let ul = document.querySelector('ul');
    let li = document.createElement('li');
    li.innerHTML = `<span class="delete">x</span><input type="checkbox"><label>${value}</label>`;
    ul.appendChild(li);
    document.querySelector('.todolist').computedStyleMap.display = 'block';
}