const htmlController = {}
const { createTask, getTasks } = require("../controllers/task.controller")
const path = require("path")

htmlController.gethtml = async(req, res) => {
    try{
        res.sendFile(path.join(__dirname, '../htmls/index.html'));
    }catch(error){
        return res.status(400).json({status:"html file send fail", error});
    }
}

module.exports = htmlController