const figlet =require("figlet");
const args=process.argv;
figlet(args[2], function (err, data) {
  if (err) {
    console.log("Something went wrong...");
    console.dir(err);
    return;
  }
  console.log(data);
});