let contextList = ['manage', 'view'];
function changeContext(contextName) {
    console.log(contextList.hasOwnProperty(contextName));
    let main_info = document.getElementById("main_context"); 
    if (!contextList.hasOwnProperty(contextName))
    {
        main_info.innerHTML = "<p>Can't found " + contextName + ".</p>";
        return;
    }
    main_info.innerHTML = "";
}

function test() {
    console.log("just for test");
}
