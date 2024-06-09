export class Model{

    handleSearch(){
        const input = document.getElementById('search-textinput');
        $.ajax({
            type: "POST",
            url: '../search.php',
            data: {action: 'getItems', text: input.value, page: 1},
            success:function(n){
                console.log(n);
            }
        });
    }
    
}



export default Model;

