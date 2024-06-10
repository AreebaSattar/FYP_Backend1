//assign_role_json//
console.log("hello world")

$.ajax({
    type:'GET',
    Url:'/assign_role_json/',
    succes: function(response){
        console.log(response)
    },
    error: function(response){
        console.log(response)
    }
})