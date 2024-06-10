import {Model} from './Model.js';

const itemList = document.getElementById('item-group');



export class View{
    displayItems(itemArray){
        itemList.replaceChildren();
        for(let i = 0; i < Object.keys(itemArray).length; i++){
            const div = document.createElement('div');
            div.className = 'item-card';
            const li = document.createElement('li');
            const addCartButton = document.createElement('button');
            addCartButton.appendChild(document.createTextNode('Add to Cart'));
            addCartButton.addEventListener('click', ()=>Model.AddCart(itemArray[i]['ItemName'], itemArray[i]['Type'], itemArray[i]['Price']));
            li.appendChild(document.createTextNode(itemArray[i]['ItemName'] + ' (' + itemArray[i]['Type'] + ")"));
            li.appendChild(document.createElement('br'));
            li.appendChild(document.createTextNode('$ ' + itemArray[i]['Price']));
            li.appendChild(document.createElement('br'));
            li.appendChild(addCartButton);
            div.appendChild(li);
            itemList.appendChild(div);
        }
    }

    displayCart(itemArray){
        const ul = document.getElementById('item-group');
        itemArray.forEach((element) => {
            const div = document.createElement('div');
            div.className = 'item-card';
            const li = document.createElement('li');
            li.appendChild(document.createTextNode(element['name'] + ' (' + element['type'] + ")"));
            li.appendChild(document.createElement('br'));
            li.appendChild(document.createTextNode('$ ' + element['price']));
            li.appendChild(document.createElement('br'));

            div.appendChild(li);
            ul.appendChild(div);
        });
    }
    displayUsers(itemArray){
        for(let i = 0; i < Object.keys(itemArray).length; i++){
            const div = document.createElement('div');
            div.className = 'item-card';
            const li = document.createElement('li');
            const editButton = document.createElement('button');
            const deleteButton = document.createElement('button');
            editButton.appendChild(document.createTextNode('Edit'));
            deleteButton.appendChild(document.createTextNode('Delete'));
            editButton.addEventListener('click', ()=>Model.editUser(itemArray[i]['ID']));
            deleteButton.addEventListener('click', ()=>Model.deleteUser(itemArray[i]['ID']));
            li.appendChild(document.createTextNode(itemArray[i]['Username']));
            li.appendChild(document.createElement('br'));
            li.appendChild(editButton);
            li.appendChild(deleteButton);
            div.appendChild(li);
            itemList.appendChild(div);
        }
    }
}