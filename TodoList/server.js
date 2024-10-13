const express = require("express");
const mongoose = require("mongoose");
const bodyParser = require("body-parser");
const cors = require("cors");
const indexRouter = require("./routes/index");
require("dotenv").config();

const app = express();
app.use(cors());

app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.use("/api", indexRouter);

const mongoURI = process.env.MONGODB_LOCAL;
mongoose.connect(mongoURI).then(() => console.log("mongoose connected")).catch((err) => console.log("mongoose connect failed", err));

app.listen(8080, () => console.log("server on at 8080")) //.catch((err) => console.log("listen failed : " + err));