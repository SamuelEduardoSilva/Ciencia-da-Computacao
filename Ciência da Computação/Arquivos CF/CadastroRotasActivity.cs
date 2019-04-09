
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using BrasilCardAppLojistaXamarin.Droid.Helper;

namespace BrasilCardAppLojistaXamarin.Droid
{
    [Activity(Label = "Cadastro de Rotas", Theme = "@style/CF", MainLauncher = true)]
    public class CadastroRotasActivity : Android.Support.V7.App.AppCompatActivity
    {

        private EditText local, horario, data;
        private Spinner veiculo;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            SetContentView(Resource.Layout.CadastroRotas);

            local = FindViewById<EditText>(Resource.Id.local);
            horario = FindViewById<EditText>(Resource.Id.horario);
            data = FindViewById<EditText>(Resource.Id.data);
            veiculo = FindViewById<Spinner>(Resource.Id.veiculo);

            Toolbar();
            data.AddTextChangedListener(new MaskHelper(data, MaskHelper.DATA_MASK));


            String[] veiculos = new String[]
            {
                "Veículo",
                "HCC-1217", "HSS-1233", "FUD-3811"
            };

            ArrayAdapter<String> spinnerArrayAdapter;
            spinnerArrayAdapter = new ArrayAdapter<String>(this, Android.Resource.Layout.SimpleListItem1, veiculos);
            this.veiculo.Adapter = spinnerArrayAdapter;
            this.veiculo.ItemSelected += new EventHandler<AdapterView.ItemSelectedEventArgs>(spinner_ItemSelectedVeiculo);
        }

        private void spinner_ItemSelectedVeiculo(object sender, AdapterView.ItemSelectedEventArgs e)
        {
            Spinner spinner = (Spinner)sender;

            if (spinner.GetItemAtPosition(e.Position) != null)
            {

               

            }
        }

        /// <summary>
        /// Monta toolbar
        /// </summary>
        private void Toolbar()
        {

            Android.Support.V7.Widget.Toolbar toolbar = FindViewById<Android.Support.V7.Widget.Toolbar>(Resource.Id.toolbar);

            SetSupportActionBar(toolbar);
            toolbar.Title = Title;
       //     toolbar.SetLogo(Resource.Drawable.cf_bus);

            if (SupportActionBar != null)
            {
                SupportActionBar.SetDisplayHomeAsUpEnabled(true);
            }
            if (Build.VERSION.SdkInt >= BuildVersionCodes.Lollipop)
            {
                Window.AddFlags(WindowManagerFlags.DrawsSystemBarBackgrounds);
            }
        }

        /// <summary>
        /// Captura os eventos de click nos itens do menu do aplicativo.
        /// Caso seja clicado na opcao voltar a Activity e finalizada
        /// </summary>
        /// <returns>bool</returns>
        public override bool OnOptionsItemSelected(IMenuItem item)
        {
            if (item.ItemId != Android.Resource.Id.Home)
                return base.OnOptionsItemSelected(item);

            Finish();

            return true;
        }
    }
}
