type t;
[@bs.module "aws-amplify"] external amplify: t = "default";

module Configure = {
  type config;
  [@bs.module "../aws-exports.js"] external awsConfig: config = "default";

  [@bs.send] external configure: (t, config) => unit = "configure";
  let configure = configure(amplify, awsConfig);
};
let configure = () => Configure.configure;