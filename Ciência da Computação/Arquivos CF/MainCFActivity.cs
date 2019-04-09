
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Support.V4.View;
using Android.Views;
using Android.Widget;
using BrasilCardAppLojistaXamarin.Bean;
using BrasilCardAppLojistaXamarin.Droid.View;
using BrasilCardAppLojistaXamarin.Model;
using BrasilCardAppLojistaXamarin.ViewModel;

namespace BrasilCardAppLojistaXamarin.Droid
{
    [Activity(Label = "Circula Fácil",Theme = "@style/CF")]
    public class MainCFActivity :Android.Support.V7.App.AppCompatActivity, Android.Support.Design.Widget.NavigationView.IOnNavigationItemSelectedListener
    {
        ListView listaRotas;
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.MainCF);


            Rota canna = new Rota("Padaria Cannã","08:20","19-11-2018","HCC-1712");
            Rota nenzona = new Rota("Bar da Nenzona", "10:30", "19-11-2018", "HCC-1712");
            List<Rota> rotas = new List<Rota>();
            rotas.Add(canna);
            rotas.Add(nenzona);

            listaRotas = FindViewById<ListView>(Resource.Id.listaRotas);

            Toolbar();
            listaRotas.Adapter = new RotasAdapter(this, rotas);

            if (Build.VERSION.SdkInt >= BuildVersionCodes.Lollipop)
            {
                Window.AddFlags(WindowManagerFlags.DrawsSystemBarBackgrounds);
            }

        }

        /// <summary>
        /// Ao clicar em voltar
        /// </summary>
        public override void OnBackPressed()
        {

            Android.Support.V4.Widget.DrawerLayout drawerLayout = FindViewById<Android.Support.V4.Widget.DrawerLayout>(Resource.Id.drawerLayout);

            if (drawerLayout.IsDrawerOpen(GravityCompat.Start))
            {
                drawerLayout.CloseDrawer(GravityCompat.Start);
            }
            else
            {
                base.OnBackPressed();
            }
        }

        /// <summary>
        /// Ao voltar a esta tela atualiza o menu
        /// </summary>
        protected override void OnResume()
        {

            base.OnResume();
            //Conteudo();
            //Menu();
        }

        /// <summary>
        /// Seta as opçoes do menu superior
        /// </summary>
        /// <param name="menu"></param>
        /// <returns></returns>
        public override bool OnCreateOptionsMenu(IMenu menu)
        {
            MenuInflater.Inflate(Resource.Menu.main, menu);
            return true;
        }

        /// <summary>
        /// Acao do menu superior
        /// </summary>
        /// <param name="item"></param>
        /// <returns></returns>
        public override bool OnOptionsItemSelected(IMenuItem item)
        {
            switch (item.ItemId)
            {
                case Resource.Id.actionExit:
                    Finish();
                    return true;

            }
            return base.OnOptionsItemSelected(item);
        }

        /// <summary>
        /// Monta o menu superior horizontal 
        /// </summary>
        private void Toolbar()
        {
            Android.Support.V7.Widget.Toolbar toolbar = FindViewById<Android.Support.V7.Widget.Toolbar>(Resource.Id.toolbar);
            Android.Support.V4.Widget.DrawerLayout drawerLayout = FindViewById<Android.Support.V4.Widget.DrawerLayout>(Resource.Id.drawerLayout);
            Android.Support.Design.Widget.NavigationView navView = FindViewById<Android.Support.Design.Widget.NavigationView>(Resource.Id.navView);

            SetSupportActionBar(toolbar);

            SupportActionBar.SetHomeAsUpIndicator(Resource.Drawable.bolt_toolbar);
            SupportActionBar.SetDisplayHomeAsUpEnabled(true);

            toolbar.Title = Title;
            toolbar.SetLogo(Resource.Drawable.bolt_toolbar);

            Android.Support.V7.App.ActionBarDrawerToggle toggle = new Android.Support.V7.App.ActionBarDrawerToggle(
                    this, drawerLayout, toolbar, Resource.String.navigation_drawer_open, Resource.String.navigation_drawer_close);

            drawerLayout.SetDrawerListener(toggle);

            toggle.SyncState();

            navView.SetNavigationItemSelectedListener(this);

        }

        /// <summary>
        /// Monta menu com base nas funcionalidades ativas
        /// </summary>
        public async void Menu()
        {
            Android.Support.Design.Widget.NavigationView navView = FindViewById<Android.Support.Design.Widget.NavigationView>(Resource.Id.navView);

            FuncionalidadeViewModel view = await MainModel.BuscarFuncionalidadesAtivas();

            if (view.funcionalidades != null)
            {

                if (view.funcionalidades.Count > 0)
                {

                    for (int i = 0; i < navView.Menu.Size(); i++)
                    {

                        IMenuItem item = navView.Menu.GetItem(i);

                        string tituloItem = item.TitleCondensedFormatted.ToString().ToLower();

                        foreach (Funcionalidade fun in view.funcionalidades)
                        {

                            if (fun.guid.ToLower().Equals(tituloItem))
                            {

                                item.SetEnabled(true);
                                item.SetVisible(true);
                                break;
                            }
                        }
                    }
                }
            }

            //BuscarDadosUsuario(navView);

        }
        /// <summary>
        /// Lista os dados do usuario no menu
        /// </summary>
        /// <param name="navView"></param>
        //private void BuscarDadosUsuario(Android.Support.Design.Widget.NavigationView navView)
        //{

        //    TextView txUsuario = (TextView)navView.GetHeaderView(0).FindViewById(Resource.Id.nomeUsuario);
        //    TextView txUltimoAcesso = (TextView)navView.GetHeaderView(0).FindViewById(Resource.Id.ultimoAcesso);
        //    ImageView imgUsuario = (ImageView)navView.GetHeaderView(0).FindViewById(Resource.Id.imgUsuario);

        //    txUsuario.Text = (((ApplicationData)(Application.Context)).getLojista().nome);
        //    txUltimoAcesso.Text = ((((ApplicationData)(Application.Context)).getLojista().ultimoAcesso ?? DateTime.Now).ToString("dd/MM/yyyy HH:mm:ss"));

        //    CarregarImagemUsuario(imgUsuario, ((ApplicationData)(Application.Context)).getLojista().urlImagemLojista, ((ApplicationData)Application.Context).getLojista().sexo);
        //}

        /// <summary>
        /// Carrega a img perfil Lojista no menu
        /// </summary>
        /// <param name="imgUsuario"></param>
        /// <param name="urlImagemLojista"></param>
        /// <param name="sexo"></param>
        private void CarregarImagemUsuario(ImageView imgUsuario, string urlImagemLojista, int sexo)
        {

            int size = (Build.VERSION.SdkInt > BuildVersionCodes.Honeycomb) ? 90 : 60;

            if (!String.IsNullOrEmpty(urlImagemLojista))
            {

                int imgDefault = (sexo > 0) ? Resource.Drawable.user_default_female : Resource.Drawable.user_default_male;

                Square.Picasso.Picasso.With(Application.Context)
                        .Load(urlImagemLojista)
                        .Resize(size, size)
                        .CenterCrop()
                        .Error(imgDefault)
                        .Placeholder(imgDefault)
                        .Into(imgUsuario);
            }
        }

        private void LoginLojistaClick(object sender, EventArgs e)
        {
            Intent intent = new Intent(this, typeof(LoginLojistaActivity));
            StartActivity(intent);
        }
        /// <summary>
        /// Acao do menu
        /// </summary>
        /// <param name="item">IMenuItem</param>
        public bool OnNavigationItemSelected(IMenuItem item)
        {
            int id = item.ItemId;

            if (id == Resource.Id.login_lojista_item)
            {
                loginLojista();
            }
            else if (id == Resource.Id.aprovacao)
            {
                aprovacao();
            }


            Android.Support.V4.Widget.DrawerLayout drawerLayout = FindViewById<Android.Support.V4.Widget.DrawerLayout>(Resource.Id.drawerLayout);

            drawerLayout.CloseDrawer(GravityCompat.Start);

            return true;
        }

        private void aprovacao()
        {
            Intent intent = new Intent(this, typeof(AprovacaoInstantaneaActivity));
            StartActivity(intent);
        }

        private void loginLojista()
        {
            Intent intent = new Intent(this, typeof(LoginLojistaActivity));
            StartActivity(intent);
        }

    }
}
