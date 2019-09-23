[@react.component]
let make = () => {
  <header>
    <div className="nav-container">
      <a href="#" className="nav-link"> {React.string("Home")} </a>
      <a href="#" className="nav-link"> {React.string("Search")} </a>
      <a href="#" className="nav-link"> {React.string("Dashboard")} </a>
    </div>
    <div className="user-menu"> <UserMenu /> </div>
    <div className="user-menu"> <UserMenuWithHook /> </div>
    <div className="user-menu"> <UserMenuAws /> </div>
  </header>;
};
