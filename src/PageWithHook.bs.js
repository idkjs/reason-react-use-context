// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var UserContext$ReactHooksTemplate = require("./UserContext.bs.js");

function PageWithHook(Props) {
  var match = UserContext$ReactHooksTemplate.useUser(/* () */0);
  var user = match[0];
  return React.createElement(React.Fragment, undefined, React.createElement("h1", undefined, "A page"), user ? React.createElement("span", {
                    className: "user-message"
                  }, "Welcome, " + (user[0] + "!")) : React.createElement("span", {
                    className: "user-message"
                  }, "Sneaky, you are browsing anonymously!"));
}

var make = PageWithHook;

exports.make = make;
/* react Not a pure module */
