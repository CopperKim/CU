const express = require("express");
const router = express.Router();

const { createTask, getTasks, deleteTask } = require("../controllers/task.controller")
const { gethtml } = require("../controllers/html.controller")

router.get("/task", gethtml);
router.get("/task/request", getTasks)
router.post("/task", createTask);
router.put("/task/:id");
router.delete("/task/:id", deleteTask);

module.exports = router