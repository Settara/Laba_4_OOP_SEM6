#include "IGMS.h"

void IGMS::Management(IDinamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem])
{
	//��� ������ ����� �������� ��� ������� ����� ������ ������� ���������
	do
	{	
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//���������� ������
				CurrentValue = DinBase->GetTemperatureCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
				cout << endl << "������� �������� �����������: " << CurrentValue;
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					cout << endl << "����������� ���������� �������� �����������: " << Database->GetInformation(temperatureMax);
					cout << endl << "����������� ������ ��� ������ ���� ";
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "�������� ����������";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "��������� ����";
						}
					}
				}
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					cout << endl << "���������� ���������� �������� �����������: " << Database->GetInformation(temperatureMin);
					cout << endl << "����������� ������ ��� ������ ���� " ;
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "��������� ����";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "��������� ����������";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//���������� ������
					CurrentValue = DinBase->GetHumidityCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
					cout << endl << "������� �������� ���������: " << CurrentValue;
					//���� ��������� ������ ��� ������ ���� 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						cout << endl << "����������� ���������� �������� ���������: " << Database->GetInformation(humidityMax);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "��������� ����";
							}
						}
					}
					//���� ��������� ������ ��� ������ ����
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						cout << endl << "���������� ���������� �������� ���������: " << Database->GetInformation(humidityMin);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "��������� ����";
							}
						}
						//���������� ������� ������ ����� ����� ������
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "����� ����� ��������";
								}
								else
								{
									cout << endl << "�� ������� ����";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //���������� ������
						CurrentValue = DinBase->GetLightingCurrent();//�������� �������� � ������� � ���������� � ���� ������� ��������
						cout << endl << "������� �������� ������������: " << CurrentValue;
						//���� ������������ ������ ��� ������ ���� 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							cout << endl << "����������� ���������� �������� ������������: " << Database->GetInformation(lightingMax);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "��������� �����";
								}
							}
						}
						//���� ������������ ������ ��� ������ ����
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							cout << endl << "���������� ���������� �������� ������������: " << Database->GetInformation(lightingMin);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "�������� �����";
								}
							}
						}
					}
					else
					{
						//������ �� ������
					}
				}
			}
		}
		//����� ����� �������� �����-�� ����� � ��������� ������
		sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0) 
		{
			Working = false;
		}
	} while (Working == true);
}