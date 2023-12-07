//** You have to just write sudo npm install -g nodemon for installing globally** 
const express=require("express");
const app= express();
// console.dir(app);
let port=3000;//custom port one more is 8080
app.listen(port,()=>{
    console.log(`app is listening on ${port}`);
});
// for accessing server go to browser and type localhost:3000
obj={
    name:"apple",
    color:"red",
};
code="<h1>Fruits</h1><ul><li>Apple</li><li>Mango</li></ul>  ";
app.get("/",(req,res)=>{
    res.send("hello, I am Groot...");
});

app.get("/:username/:id",(req,res)=>{
    // console.log(req.params);
    let {username,id}=req.params;
    let htmlStr=`<h1>Welcome to the page of @${username}</h1>`;
    res.send(htmlStr);
});

app.get("/search",(req,res)=>{
    // console.log(req.query);
    let {q}= req.query;
    if(!q){
        res.send("nothing searched");
    }
    res.send(`<h1>search results for query: ${q}</h1>`);
});
// app.get("/apple",(req,res)=>{
//     res.send("you contacted apple path");
// });
// app.get("/mango",(req,res)=>{
//     res.send("you contacted mango path");
// });
app.get("*",(req,res)=>{
    res.send("path does not exist!!!");
});
// app.post("/",(req,res)=>{
//     res.send("you send a post request to the root");
// });



// app.use((req,res)=>{
//     // console.log(res);
//     console.log("request recieved");
//     // res.send(obj);
//     res.send(code);
// });
