const Task = require("../models/Task")
const taskController = {}

taskController.createTask = async(req, res) => {
    try{
        const {task, duedate} = req.body
        const newTask = new Task({task, duedate})
        await newTask.save()
        res.status(200).json({status:"success", data:newTask})
    }catch(error){
        res.status(400).json({status:"fail", error})
    }
};

taskController.getTasks = async(req, res) => {
    try{
        const Tasks = await Task.find()
        res.status(200).json({status:"success", data:Tasks});
    }catch(error){
        res.status(400).json({status:"fail", error})
    }
}

// taskController.modifyTask = async(req, res) => {
//     try{
//         const taskId = req.params.id;
//         const Task = await Task.findbyId(taskId)
//         Task.

//     }catch(error){
//         res.status(400).json({status:"fail", error})
//     }
// }

taskController.deleteTask = async (req, res) => {
    try {
        const taskId = req.params.id
        // console.log(taskId)
        const result = await Task.deleteOne({ _id: taskId });
        if (result.deletedCount === 1) {
            console.log("Document deleted successfully");
        } else {
            console.log("No document found with that _id");
        }
        res.status(200).json({status : "successful", data : taskId})
    } catch (error) {
        res.status(400).json({status:"fail", error})
    }
};

module.exports=taskController