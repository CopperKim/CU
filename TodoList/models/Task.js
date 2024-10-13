const mongoose = require("mongoose")

const Schema = mongoose.Schema

const taskSchema = Schema({
    task:{type:String, require:true, default:"Whatever you want"},
    duedate:{type:String, require:true, default:"Whenever you want"}
}, {timestamps:true});

const Task = mongoose.model("Task", taskSchema);
module.exports = Task;

// hihi